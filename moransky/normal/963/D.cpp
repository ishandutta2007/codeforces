#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define debug(x) cerr<<#x<<' '<<x<<'\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
struct Trie {
    int next[maxn][26],fail[maxn],id[maxn],root,cnt;
    int match[maxn];
    int newnode() {
        rep(i,0,25) next[cnt][i]=-1;
        id[cnt++]=0;
        return cnt-1;
    }
    void init() {
        cnt=0;
        root=newnode();
    }
    void ins(char a[],int x) {
        int len=strlen(a),now=root;
        rep(i,0,len-1) {
            if(next[now][a[i]-'a']==-1)
                next[now][a[i]-'a']=newnode();
            now=next[now][a[i]-'a'];
        }
        id[now]=x;
    }
    void build() {
        queue<int> q;
        fail[root]=root;
        rep(i,0,25) {
            if(next[root][i]==-1) {
                next[root][i]=root;
            }
            else {
                fail[next[root][i]]=root;
                match[next[root][i]]=root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty()) {
            int now=q.front();
            q.pop();
            rep(i,0,25) {
                if(next[now][i]==-1) next[now][i]=next[fail[now]][i];
                else {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                    int tmp=fail[next[now][i]];
                    if(id[tmp]>0) match[next[now][i]]=tmp;
                    else match[next[now][i]]=match[tmp];
                }
            }
        }
    }
}AC;
vi pos[maxn];
char str[maxn],a[maxn];
int k[maxn],lena[maxn];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>str;
    int n;
    cin>>n;
    AC.init();
    rep(i,1,n) {
        cin>>k[i]>>a;
        lena[i]=strlen(a);
        AC.ins(a,i);
    }
    AC.build();
    int len=strlen(str),now=0;
    rep(i,0,len-1) {
        now=AC.next[now][str[i]-'a'];
        for(int t=now;t;t=AC.match[t]) {
            if(AC.id[t]) pos[AC.id[t]].pb(i);
        }
    }
    rep(i,1,n) {
        if(k[i]>pos[i].size()) cout<<-1<<'\n';
        else {
            int ans=inf;
            for(int l=0,r=k[i]-1;r<pos[i].size();l++,r++) {
                ans=min(ans,pos[i][r]-pos[i][l]+lena[i]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
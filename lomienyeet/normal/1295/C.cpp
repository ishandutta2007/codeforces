#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
void eat(){
    string a,b;
    cin>>a>>b;
    // I DONT HAVE MY FUCKING TRIE MOBAN
    a="_"+a;
    b="_"+b;
    int nxt[a.length()+5][26],freq[26]={};
    memset(nxt,0,sizeof nxt);
    for(int i=a.length()-1;i>0;i--){
        for(int j=0;j<26;j++)nxt[i][j]=freq[j];
        freq[a[i]-'a']=i;
    }
    for(int i=0;i<26;i++)nxt[0][i]=freq[i];
    int ans=0,ptr=1;
    while(ptr<b.length()){
        int go=nxt[0][b[ptr]-'a'];
        ans++;
        if(!go){
            ans=-1;
            break;
        }
        while(go&&ptr<b.length()){
            ptr++;
            auto x=b[ptr]-'a';
            go=nxt[go][x];
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}
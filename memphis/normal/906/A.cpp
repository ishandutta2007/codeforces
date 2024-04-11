#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N=100005;

int n,m,a[N];
bool ss[26],bb[26];
char s[N];

int main(){
    scanf("%d",&n);
    int cnt=0,ans=0;
    rep(i,1,n){
        //if(i==n) break;
        char bbb;
        if(cnt==25){
            rep(j,0,25) if(ss[j]==0) bbb=j+'a';
        }
        char ch=getchar();
        while(ch!='!'&&ch!='.'&&ch!='?') ch=getchar();
        if(ch=='.'){
            
            scanf("%s",s+1);
            if(cnt==25) {
                continue;
            }
            int m=strlen(s+1);
            rep(j,1,m) {
                int v=s[j]-'a';
                if(ss[v]==0) ss[v]=1,++cnt;
            }
        }
        if(ch=='!'){
            memset(bb,0,sizeof(bb));
            scanf("%s",s+1);
            if(cnt==25) {
                ++ans;
                continue;
            }
            int m=strlen(s+1);
            rep(j,1,m){
                int v=s[j]-'a';
                bb[v]=1;
            }
            rep(j,0,25) if(bb[j]==0){
                if(ss[j]==0) ss[j]=1,++cnt;
            }
        }
        if(ch=='?'){
            scanf("%s",s+1);
            //if(i==n) break;
            if(cnt==25 && s[1]!=bbb){
                ++ans;
                continue;
            }
            int v=s[1]-'a';
            if(ss[v]==0){
                ++cnt;
                ss[v]=1;
            }
        }
        //printf("cnt = %d\n",cnt);
    }
    printf("%d\n",ans);
}
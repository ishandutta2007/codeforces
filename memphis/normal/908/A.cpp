#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <bitset>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

const int N=100005;

int n,cnt;
char s[N];

int main(){
    //scanf("%d",&n);
    scanf("%s",s+1);
    n=strlen(s+1);
    rep(i,1,n){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
                || s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' ||
                s[i]=='9')
            ++cnt;
    }
    printf("%d\n",cnt);
}
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;
int n;

vector <int> v;

ll ans;
int k;
char ch[4020];
int in[4020],sm[4020];
int da[40040];

int f(int x)
{
    if(x>40000)return 0;
    return da[x];
}

int main()
{
    scanf("%d",&n);
    int i,j;
    scanf("%s",ch);
    k=strlen(ch);
    for(i=0;ch[i];i++)in[i+1]=ch[i]-'0';
    for(i=1;i<=k;i++)sm[i]=sm[i-1]+in[i];
    for(i=0;i<=k;i++){
        for(j=i+1;j<=k;j++){
            da[sm[j]-sm[i]]++;
        }
    }
    int t = k*(k+1)/2;
    if(n==0)printf("%lld\n",(ll)f(0)*f(0) + 2LL*f(0)*(t-f(0)));
    else{
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i==n)ans+=(ll)f(i)*f(n/i);
            else ans+=(ll)f(i)*f(n/i)*2ll;
        }
    }
    printf("%lld",ans);
    }
    return 0;
}
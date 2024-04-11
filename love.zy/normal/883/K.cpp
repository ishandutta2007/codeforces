/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool used[200001];
int a[200001],b[200001];
set<pair<int,int>> s;
int main()
{
    int n;
    scanf("%d",&n);
    LL ans=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        ans-=a[i];
        b[i]+=a[i];
        s.insert(make_pair(b[i],i));
    }
    bool flag=true;
    while(!s.empty()){
        //printf("1 %d\n",s.size());
        int i=s.begin()->second;s.erase(s.begin());
        used[i]=true;
        ans+=b[i];
        if(i&&!used[i-1]){
            s.erase(make_pair(b[i-1],i-1));
            //printf("2 %d\n",s.size());
            b[i-1]=min(b[i-1],b[i]+1);
            if(a[i-1]>b[i-1]){flag=false;break;}
            s.insert(make_pair(b[i-1],i-1));
        }
        if(i!=n-1&&!used[i+1]){
            s.erase(make_pair(b[i+1],i+1));
            //printf("3 %d\n",s.size());
            b[i+1]=min(b[i+1],b[i]+1);
            if(a[i+1]>b[i+1]){flag=false;break;}
            s.insert(make_pair(b[i+1],i+1));
        }
    }
    if(!flag)printf("-1");
    else{
        printf("%lld\n",ans);
        for(int i=0;i<n;i++)
            printf("%d ",b[i]);
    }
    return 0;
}
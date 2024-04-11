#include<bits/stdc++.h>
using namespace std;
const int maxn=5210;
bool a[maxn][maxn];
char s[2000];
vector<int> d;
int dp[maxn][maxn],f[17][5],n,x,v,fuck;
int main(){
      ios::sync_with_stdio(false);
      cin.tie(0); cout.tie(0);
    for(int i=1;i<=15;i++){
            x=i;
        for(int j=4;j>=1;j--){
            f[i][j]=x%2;
            x/=2;
        }
    }
  /*  for(int i=1;i<=4;i++)
    printf("%d",f[14][i]);
    printf("\n");*/
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<n/4;j++){
            if(s[j]>='A')
            v=s[j]-'A'+10;
            else
            v=s[j]-'0';
            for(int k=1;k<=4;k++){
                a[i][4*j+k]=f[v][k];
              //  printf("%d",a[i][4*j+k]);
            }
        }
      //  printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }

    
    v=sqrt(n);
    for(int i=v;i>=1;i--){
        if(n%i==0){
            if(i*i!=n)
            d.push_back(i);
            d.push_back(n/i);
        }
    }
    sort(d.begin(),d.end());
    bool ch=true;
    for(int i=0;i<d.size();i++){
        x=n/d[i];
        ch=true;
        v=x*x;
        for(int j=x;j<=n;j+=x){
            for(int k=x;k<=n;k+=x){
                    fuck=dp[j][k]-dp[j-x][k]-dp[j][k-x]+dp[j-x][k-x];
                if(fuck==0||fuck==v)
                    continue;
                else
                    ch=false;
            }
        }
        if(ch){
            cout<<x;
            return 0;
        }
    }
    //printf("1");
}
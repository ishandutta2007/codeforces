// holy fuck i hate constructives so much

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)cin>>arr[i][j];
            else arr[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int a=i,b=i;
        for(int j=0;j<arr[i][i]-1;j++){
            if(!arr[a][b-1]&&b>1)b--;
            else a++;
            arr[a][b]=arr[i][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--)eat();
}
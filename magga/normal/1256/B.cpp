#include<bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void solve()
{
    int n;cin>>n;
    int arr[n];
    int budget = n-1;
    bool flag [n];
    long long int dp[n+1];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        dp[arr[i]]=i;
    }
    long long int min = 1000;
    long long int index = 0;
    long long int end = 0;
    long long int ans[1000]{0};
    for(long long int i=0;i<n;i++){
        min = 1000;
        index = 0;
        for(long long int j=end;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        ans[end]=min;
        if(end!=index){
        for(long long int j=end+1;j<=index;j++){
            ans[j]=arr[j-1];
        }
        end = index;
        arr[index]=ans[index];
        }else{
            end++;
        }
        
        if(ans[n-1]!=0){
            break;
        }
    }
    for(long long int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}
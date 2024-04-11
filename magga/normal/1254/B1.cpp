    #include<bits/stdc++.h>
    using namespace std;
    void pre(){}
    long long int n;
    long long int arr[1000001];
    long long int ret(long long int j){
        long long int val = 0;
        long long int curr = 0;
        for(long long int i=0;i<n;i++){
            val+=min(curr,j-curr);
            curr+=arr[i];
            curr%=j;
        }
        return val;
    }
    void solve(){
        cin>>n;
        long long int sum = 0;
        for(long long int i=0;i<n;i++){cin>>arr[i];sum+=arr[i];}
        if(sum<2){
            cout<<-1<<"\n";
            return;
        }
        long long int ans = 1e18;
        vector<long long int>v;
        for(long long int i=2;i<=sqrt(sum);i++){
            if(sum%i==0){
                v.push_back(i);
            }
            while(sum%i==0){
                sum/=i;
            }
        }
        if(sum!=1){
            v.push_back(sum);
        }
        for(long long int i:v){
            ans=min(ans,ret(i));
        }
        cout<<ans<<"\n";
    }
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        pre();
        long long int num = 1;
        //cin>>num;
        for(long long int i=0;i<num;i++){
            solve();
        }   
    }
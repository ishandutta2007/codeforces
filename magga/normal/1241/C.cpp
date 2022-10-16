#include<bits/stdc++.h>
using namespace std;
long long int calculate(long long int n,long long int arr[],long long int x,long long int y,long long int a,long long int b){
    long long int k = (a*b)/__gcd(a,b);
    long long int h = n/k;
    long long int ans = 0;
    long long int i = 0;
    while(i<h){
        ans+=((x+y)*arr[i]);
        i++;
    }
    if(x<y){
        long long int im1 , im2 ;
        im1 = x;
        im2 = a;
        x = y;
        y = im1;
        a = b;
        b = im2;
    }
    long long int t1 , t2;t1= n/a;t2 = n/b;
    while(i<t1){
        ans+=((x)*arr[i]);
        i++;       
    }
    while(i<t1+t2-h){
        ans+=((y)*arr[i]);
        i++;       
    }
    return ans;
}
void solve()
{
    long long int n;cin>>n;
    long long int arr[n];
    bool ya  = false;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]/=100;
    }
    
    sort(arr, arr+n, greater<long long int>()); 
    long long int a,b,x,y,target;cin>>x>>a>>y>>b>>target;
    long long int start = 1;
    long long int max = n;
    long long int ref = -1000;
    long long int mid = (start+max)/2;
    while(max>=start){
        //cout<<calculate(mid,arr,x,y,a,b)<<" "<<mid<<" "<<target<<"\n";
        if(calculate(mid,arr,x,y,a,b)>=target){
            ya = true;
            max = mid - 1;
            ref = mid;
            mid = (start+max)/2;
            
        }else{
            start = mid + 1;
            mid = (start+max)/2;
        }
    }
    if(ya){
        cout<<ref<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
#include<bits/stdc++.h>
using namespace std;
long long int val( char c ){
    return int(c)-int('0');
}
void solve(){
    long long int n,d;cin>>n;
    long long int arr[n];
    long long int a = 0, b = 0 ;
    for( long long int i = 0 ; i < n ; i++ ){
        cin>>d;
        if( i%2 == 0 ){
            a += d/2;
            b += d-d/2;
        }else{
            b += d/2;
            a += d-d/2;
        }
    }
    cout<<min(a,b)<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}
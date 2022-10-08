#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define loop(i,a,b) for(int i=a,i<=b;++i)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define loopr(t,a,b) for(int i=a,i>=b;--i)
#define mod 1e9+7
#define endl "\n"
#define loopit(it,container) for(auto it=container.begin();it!=container,end();it++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>



int main() {

       string a,b;
       cin>>a;
       cin>>b;
       int count4a=0,count7a=0,count4b=0,count7b=0;
       for(int i=0;i<a.size();++i){
        if(a[i]=='7')
            count7a++;
        else
            count4a++;
        if(b[i]=='7')
            count7b++;
        else
            count4b++;
       }
       int count=0;
       for(int i=0;i<a.length();++i){
        if(a[i]!=b[i])
            count++;
       }
       cout<<(count-abs(count4a-count4b))/2+abs(count4a-count4b) ;



    
}
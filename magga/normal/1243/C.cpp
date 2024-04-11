#include<bits/stdc++.h>
using namespace std;
set<long long int>s;
void primeFactors(long long int n)  
{  
    while (n % 2 == 0)  {  
        s.insert(2);
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  {  
        while (n % i == 0){  
            s.insert(i);
            n = n/i;  
        }  
    }  
    if (n > 2)  
        s.insert(n);  
} 
void solve(){
    long long int n;cin>>n;
    primeFactors(n);
    //cout<<s.size()<<"\n";
    if(s.size()==1 && n!=1){
        cout<<*s.begin()<<"\n";
    }else{
        cout<<1<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}
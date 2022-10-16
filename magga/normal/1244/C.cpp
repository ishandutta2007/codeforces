#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,w,d,p;cin>>n>>p>>w>>d;
    long long int hcf = __gcd(w,d);
    long long int lcm = w*d/hcf;
    long long int win = p/w;
    long long int rem = p%w;
    long long int draw = rem/d;
    rem%=d;
    long long int copy = p;
    bool falg = false;
    long long int change = 0;
    if(p%hcf!=0){
        cout<<-1<<"\n";
        return;
    }
    while(rem!=0 && change<=lcm && win>=0){
        //cout<<win<<" "<<draw<<" "<<rem<<" "<<copy<<"\n";
        win--;
        copy = win*w;
        draw = (p-copy)/d;
        change+=(w);
        rem  = (p-copy)%d;
        if(rem==0){
            falg = true;
            break;
        }
    }
    long long int loss = n-draw-win;
    //loss = 1;
    if(rem==0 && loss>=0){
        cout<<win<<" "<<draw<<" "<<n-draw-win<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}
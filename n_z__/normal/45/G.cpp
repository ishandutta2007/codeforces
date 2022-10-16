#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int q)
{
	bool isprime=true;
	for(int x=2;x*x<=q;x++)
	if(q%x==0){isprime=false;break;}
	return isprime;
}
main()
{
    int n;
    cin>>n;
    int s=n*(n+1)/2;
    if(isprime(s)){
        for(int x=1;x<=n;x++)
        cout<<1<<' ';
        return 0;
    }
    //cout<<"Not match 1"<<endl;
    if(!(s%2)){
        for(int x=3;x<=s;x+=2)
        if(isprime(x)&&isprime(s-x))
        {
            for(int y=1;y<=n;y++)
            if(x==y)cout<<2<<' ';
            else cout<<1<<' ';
            return 0;
        }
    }
    //cout<<"Not match 2"<<endl;
    if(isprime(s-2)){
        for(int x=1;x<=n;x++)
        if(x==2)cout<<2<<' ';
        else cout<<1<<' ';
        return 0;
    }
    //cout<<"Not match 3"<<endl;
    for(int x=5;x<=s-3;x+=2)
    if(isprime(x)&&isprime(s-3-x))
    {
        for(int y=1;y<=n;y++)
        if(y==3)cout<<3<<' ';
        else if(x==y)cout<<2<<' ';
        else cout<<1<<' ';
        return 0;
    }
}
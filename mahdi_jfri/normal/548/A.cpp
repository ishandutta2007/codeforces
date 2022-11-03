#include <iostream>
using namespace std;

bool check(string a,long long i,long long z)
{
    while(a[i++]==a[z--])
        if(i>=z)
        return 1;
    return 0;
}

int main()
{
    string a;
    cin >> a;
    long long s=a.size(),res=0,n;
    cin >> n;
    if(n>s || s%n>0)
        {cout<<"NO"; return 0;}
    long long x=s/n;
        for(long long i=0;i<s;i+=x)
            {
                if(check(a,i,i+x-1) == 0)
                    {
                        cout<<"NO";
                        return 0;
                    }
            }
    cout<<"YES";
}
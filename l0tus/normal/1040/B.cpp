#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K,i;
    cin >> N >> K;
    int x = N%(2*K+1);
    if(x==0) x= 2*K+1;
    if(x>=K+1) i = x-K;
    else i = 1;
    cout << (N-i)/(2*K+1)+1 << '\n';
    while(i<=N)
    {
        cout << i <<' ';
        i += 2*K+1;
    }
}
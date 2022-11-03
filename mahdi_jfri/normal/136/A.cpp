#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+20;
int b[maxn];
int a;
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> a;
        b[a-1]=i+1;
    }
    for(int i = 0 ; i < n ; i++)
        cout << b[i] << " ";
}
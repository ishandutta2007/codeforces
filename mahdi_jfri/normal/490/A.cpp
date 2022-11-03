#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
stack<int>a;
stack<int>b;
stack<int>c;
int main()
{
    int n;
    cin >> n;
    int d;
    for(int i=0 ; i < n ;i++)
    {
        cin >> d;
        if(d == 1)
            a.push(i+1);
        else if(d == 2)
            b.push(i+1);
        else
            c.push(i+1);
    }
    int k=0;
    k=min(c.size(),min(b.size(),a.size()));
    cout << k << endl;
    for(int i=0; i < k; i++)
    {
        cout << a.top() <<" "<< b.top()<< " " << c.top() << endl;
        a.pop();
        b.pop();
        c.pop();
    }
}
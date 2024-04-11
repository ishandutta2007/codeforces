#include <bits/stdc++.h>
#define va first
#define vb second
typedef long long ll;
using namespace std;
const int INF = 2e9;
const int mx = 1e5;

ll a,b;
int A[40],B[40],C[40],D[40];
int cnt = 29;
void setting()
{
    a =  b = 0;
    for(int j=0; j<=29; j++)
        {
            if(A[j]) a += (1<<j);
            if(B[j]) b += (1<<j);
        }
}
int x;
int main()
{
    ios_base::sync_with_stdio(0);
    while(cnt>=0)
    {
        setting();
        cout << "? " << a << ' ' << b << '\n';
        fflush(stdout);
        cin >> x;
        if(x==1)
        {
            while(cnt>=0)
            {
                A[cnt] = 1;
                B[cnt] = 1;
                setting();
                cout << "? " << a << ' ' << b << '\n';
                fflush(stdout);
                cin >> x;
                if(x==1)
                {
                    B[cnt] = 0;
                    setting();
                    cout << "? " << a << ' ' << b << '\n';
                    fflush(stdout);
                    cin >> x;
                    if(x==1)
                    {
                        C[cnt] = 0;
                        D[cnt] = 0;
                    }
                    else
                    {
                        C[cnt] = 1;
                        D[cnt] = 1;
                    }
                    A[cnt] = 0;
                }
                else
                {
                    C[cnt] = 1;
                    D[cnt] = 0;
                    A[cnt] = 1;
                    B[cnt] = 0;
                    cnt --;
                    break;
                }
                cnt --;
            }
        }
        else if(x==-1)
        {
            while(cnt>=0)
            {
                A[cnt] = 1;
                B[cnt] = 1;
                setting();
                cout << "? " << a << ' ' << b << '\n';
                fflush(stdout);
                cin >> x;
                if(x==-1)
                {
                    B[cnt] = 0;
                    setting();
                    cout << "? " << a << ' ' << b <<'\n';
                    fflush(stdout);
                    cin >> x;
                    if(x==1)
                    {
                        C[cnt] = 0;
                        D[cnt] = 0;
                    }
                    else
                    {
                        C[cnt] = 1;
                        D[cnt] = 1;
                    }
                    A[cnt] = 0;
                }
                else
                {
                    C[cnt] = 0;
                    D[cnt] = 1;
                    A[cnt] = 0;
                    B[cnt] = 1;
                    cnt --;
                    break;
                }
                cnt --;
            }
        }
        else if(x==0)
        {
            while(cnt>=0)
            {
                A[cnt] = 1;
                setting();
                cout << "? " << a << ' ' << b << '\n';
                fflush(stdout);
                cin >> x;
                if(x==1)
                {
                    C[cnt] = 0;
                    D[cnt] = 0;
                }
                else
                {
                    C[cnt] = 1;
                    D[cnt] = 1;
                }
                A[cnt] = 0;
                cnt --;
            }
        }
    }
    ll c =0, d= 0;
    for(int i=0; i<=29; i++)
    {
        if(C[i]) c += (1<<i);
        if(D[i]) d += (1<<i);
    }
    cout << "! " << c << ' ' << d;
}
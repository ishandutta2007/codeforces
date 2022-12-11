#include <bits/stdc++.h>
using namespace std;
int N,M,xi,yi,xf,yf;
char color;
int main()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            cin >> color;
            if(xi==0 && yi==0 && color=='B')
            {
                xi = j;
                yi = i;
            }
            if(color=='B')
            {
                xf = j;
                yf = i;
            }
        }
    cout << (yi+yf)/2 << ' ' << (xi+xf)/2;
}
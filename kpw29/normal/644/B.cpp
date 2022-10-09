#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, rozmiar;
queue <ll> q;
ll moment, dlugosc, suma;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> rozmiar;
    for (int i=1; i<=n; ++i)
    {
        cin >> moment >> dlugosc;
        while (!q.empty() && q.front() <= moment) q.pop();
        if (q.size() <= rozmiar) {
        	suma = max(suma, moment);
            ll zakonczenia = suma + dlugosc;
            suma = zakonczenia;
            q.push(zakonczenia);
            cout << zakonczenia << ' ';
        }
        else cout << "-1 ";
    }

}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn];
bool visited[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] , a[i]--;
    for(int i = 0; i < n; i++)
        if(a[i] == i)
        {
            cout << "YES\n";
            for(int j = 0; j < n; j++)
                if(j != i)
                    cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
    int k = -1;
    for(int i = 0; i < n; i++)
        if(!visited[i])
        {
            visited[i] = 1;
            int x = a[i] , z = 1;
            while(x != i)
                visited[x] = 1 , x = a[x] , z++;
            if(z & 1)
            {
                cout << "NO\n";
                return 0;
            }
            if(z == 2)
                k = i;
        }
    fill(visited , visited + maxn , 0);
    if(k == -1)
    {
        cout << "NO\n";
        return 0;
    }
    int x = k , y = a[k];
    cout << "YES\n";
    cout << x + 1 << " " << y + 1 << endl;
    for(int i = 0; i < n; i++)
    {
        if(i == x || i == y || visited[i])
            continue;
        visited[i] = 1;
        cout << x + 1 << " " << i + 1 << endl;
        bool f = 1;
        int z = a[i];
        while(z != i)
        {
            visited[z] = 1;
            if(f)
                cout << y + 1;
            else
                cout << x + 1;
            cout << " " << z + 1 << endl;
            f = !f;
            z = a[z];
        }
    }
}
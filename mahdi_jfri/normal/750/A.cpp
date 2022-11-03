#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define time tttt
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int time = 4 * 60 , n , res;
int main()
{
    int n , k , i = 1;
    cin >> n >> k;
    while(time - i * 5 >= k && i <= n)
    {
        time -= i * 5;
        res++;
        i++;
    }
    cout << res;
}
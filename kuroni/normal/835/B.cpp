#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int k, sum = 0, i;
string n;

int main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    cin >> k >> n;
    sort(n.begin(), n.end());
    for (i = 0; i < n.size(); i++)
        sum += n[i] - '0';
    if (sum >= k)
        printf("0");
    else
    {
        int cnt = 0;
        for (i = 0; i < n.size(); i++)
        {
            ++cnt;
            sum += '9' - n[i];
            if (sum >= k)
            {
                printf("%d", cnt);
                return 0;
            }
        }
    }
}
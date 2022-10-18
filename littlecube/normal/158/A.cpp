#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, k, score, adv, result = 0, i = 0;
    cin >> n >> k;
    for (; i < k; i++)
    {
        cin >> score;
        if(score > 0){
            result++;
            adv = score;
        }
    }
    for (; i < n; i++)
    {
        cin >> score;
        if(score > 0 && score >= adv){
            result++;
        }
    }
    cout << result << '\n';
}
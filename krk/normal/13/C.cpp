#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 5000;

int n, m, a[Maxn];
vector <ll> nums;
ll board[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    m = unique(nums.begin(), nums.end()) - nums.begin();
    board[0] = abs(nums[0] - a[0]);
    for (int j = 1; j < m; j++) board[j] = min(board[j-1], abs(nums[j] - a[0]));
    for (int i = 1; i < n; i++) {
        board[0] += abs(nums[0] - a[i]);
        for (int j = 1; j < m; j++)
           board[j] = min(board[j-1], board[j] + (ll)abs(nums[j] - a[i]));
    }
    cout << board[m-1] << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> visited(n+1);
    int cur = 1;
    while (!visited[cur])
    {
        visited[cur] = true;
        cur = cur - a[cur];
    }
    vector<int> answer = {cur};
    int cur1 = cur - a[cur];
    while (cur1!=cur)
    {
        answer.push_back(cur1);
        cur1 = cur1 - a[cur1];
    }
    cout<<answer.size()<<'\n';
    for (auto it: answer) cout<<it<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();


}
#include <bits/stdc++.h>

using namespace std;

//   , -1 - other
vector<pair<int, int> > v;

int main()
{
    int n, M, minimum, sum = 0, other = 0, ans = 0;
    int m[2500] = {0};
    int gr[2500];
    cin>>n>>M;
    for(int i = 0 ; i < n;i++)
    {
        int a;
        cin>>gr[i];
        gr[i];
        if (gr[i] <= M) m[gr[i] - 1]++;
        else other++;
    }
    //sort(m, m + M);
    for(int i = 0 ; i < M; i++) sum+=m[i];
    sum += other;
    minimum = sum / M;
    cout<< minimum<< ' ';
    int c = 0;
    for(int i = 0; i < M; i++) if (m[i] < minimum) c+= (minimum - m[i]);
    cout<<c;
    int last = M - 1;
    for(int i = 0; i < M; i++)
    {
        while(m[i] < minimum && other)
        {
            other--;
            m[i]++;
            v.push_back(make_pair(-1, i + 1));
        }
        if (m[i] == minimum) continue;
        while(m[i] < minimum)
        {
            if(m[last] > minimum)
            {
                m[last]--;
                m[i]++;
                v.push_back(make_pair(last + 1, i + 1));
            }
            else last--;
        }
    }
    cout<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < n; j++)
            if(v[i].first == -1 && gr[j] > M)
        {
            gr[j] = v[i].second;
            break;
        }
        else if (v[i].first == gr[j])
        {
            gr[j] = v[i].second;
            break;
        }
    }
    for(int i =0; i < n; i++) cout<<gr[i]<<' ';
    return 0;
}
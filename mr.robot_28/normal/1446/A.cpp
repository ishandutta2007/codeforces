#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
    {
        int n;
        cin >> n;
        long long w;
        cin >> w;
        vector <pair <int, int> >  wei(n);
        int ind = -1;
        long long sum = 0;
        for(int i = 0; i< n; i++)
        {
            cin >> wei[i].first;
            wei[i].second = i;
            if((ind == -1 || wei[i].first > wei[ind].first) && wei[i].first <= w)
            {
                ind = i;
            }
        }
        if(ind != -1 && wei[ind].first * 2 >= w)
        {
            cout << 1 << "\n";
            cout << ind + 1 << "\n";
        }
        else
        {
            vector <int> ans;
            sort(wei.begin(), wei.end());
            for(int i = 0; i < n; i++)
            {
                if(sum + wei[i].first > w)
                {
                    break;
                }
                sum += wei[i].first;
                ans.push_back(wei[i].second + 1);
            }
            if(sum * 2 < w)
            {
                cout << -1 << "\n";
                continue;
            }
            cout << ans.size() << "\n";
            for(int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
	return 0;
}
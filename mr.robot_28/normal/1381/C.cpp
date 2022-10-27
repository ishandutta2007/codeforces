#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		vector <int> b(n);
		vector <vector <int> > index1(n + 1);
		vector <vector <int> > index2(n + 1);
		set <int> s1;
		for(int i = 0; i < n + 1; i++)
		{
			s1.insert(i);
		}
		for(int i = 0; i < n; i++)
		{
			cin >> b[i];
			b[i]--;
			s1.erase(b[i]);
			index1[b[i]].push_back(i);
			index2[b[i]].push_back(i);
		}
		vector <int> p(n, -1);
		priority_queue <pair <int, int> > q;
		for(int i = 0; i <= n; i++)
		{
			if(index1[i].size() != 0)
			{
				q.push({index1[i].size(), i});
			}
		}
		int x1 = x;
		while(x1 > 0)
		{
			int v = q.top().second;
			q.pop();
			p[index1[v].back()] = v;
			index1[v].pop_back();
			index2[v].pop_back();
			if(index1[v].size() != 0)
			{
				q.push({index1[v].size(), v});
			}
			x1--;
		}
		deque <int> st;
		vector <int> vec;
		int maximal = -1;
		if(q.size() != 0)
		{
			st.push_back(q.top().second);
			maximal = q.top().second;
			q.pop();
		}
		while(q.size() > 0)
		{
			st.push_back(q.top().second);
			for(int j = 0; j < index1[q.top().second].size(); j++)
			{
				vec.push_back(index1[q.top().second][j]);
			}
			q.pop();
		}
		bool flag = true;
		y -= x;
		for(int i = 0; i < vec.size(); i++)
		{
			if(y == 0)
			{
				break;
			}
			if(st.size() == 1 && st.front() == b[vec[i]])
			{
				
			}
			else if(st.front() == b[vec[i]])
			{
				y--;
				int v = st.front();
				st.pop_front();
				p[vec[i]] = st.front();
				index1[st.front()].pop_back();
				if(index1[st.front()].size() == 0)
				{
					st.pop_front();
				}
				st.push_front(v);
			}
			else
			{
				y--;
				p[vec[i]] = st.front();
				index1[st.front()].pop_back();
				if(index1[st.front()].size() == 0)
				{
					st.pop_front();
				}
			}
		}
		if(maximal != -1)
		{
			for(int j = 0; j < index2[maximal].size(); j++)
			{
				if(y == 0)
				{
					break;
				}
				int ind = index2[maximal][j];
				if(st.size() == 1 && st.front() == b[ind])
				{
					
				}
				else if(st.front() == b[ind])
				{
					y--;
					int v = st.front();
					st.pop_front();
					p[ind] = st.front();
					index1[st.front()].pop_back();
					if(index1[st.front()].size() == 0)
					{
						st.pop_front();
					}
					st.push_front(v);
				}
				else
				{
					y--;
					p[ind] = st.front();
					index1[st.front()].pop_back();
					if(index1[st.front()].size() == 0)
					{
						st.pop_front();
					}
				}
			}
		}
		if(y == 0)
		{
			cout << "YES\n";
			for(int i = 0; i < n; i++)
			{
				if(p[i] == -1)
				{
					cout << *s1.begin() + 1 << " ";
				}
				else
				{
					cout << p[i] + 1 << " ";
				}
			}
			cout << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
  	return 0;
}
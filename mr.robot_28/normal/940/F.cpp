#include <bits/stdc++.h>
 
using namespace std;
int cnst;
vector <int> T, cnt2, cnt1;
vector <pair <int, int> > update;
 
vector <pair <pair <int, int>, pair <int, int> > > quest;
vector <int> A;
vector <int> v;
int get_id(int num)
{
	return lower_bound(v.begin(),v.end(),num)-v.begin()+1;
}
bool cmp(pair <pair <int, int>, pair <int, int> > a, pair <pair <int, int>, pair <int, int> > b)
{
	if(T[a.second.first] == T[b.second.first] && T[a.second.second] == T[b.second.second])
	{
		return a.first.first < b.first.first;
	}
	if(T[a.second.first] == T[b.second.first])
	{
		return T[a.second.second] < T[b.second.second];
	}
	return a.second.first < b.second.first;
}
void add(int num)
{
	cnt2[cnt1[num]]--;
	cnt2[++cnt1[num]]++;
}
void del(int num)
{
	cnt2[cnt1[num]]--;
	cnt2[--cnt1[num]]++;
}
void mod(int x, int i)
{
	i--;
	if(update[i].first >= quest[x].second.first && update[i].first <= quest[x].second.second)
	{
		del(A[update[i].first]);
		add(update[i].second);
	}
	swap(A[update[i].first], update[i].second);
}
signed main(){
	int n, q;
	cin >> n >> q;
	cnt1.resize(n + q + 1);
	cnt2.resize(n + 1);
	cnst = pow(n, 0.6666);
	A.resize(n);
	T.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		T[i] = i / cnst;
		v.push_back(A[i]);
	}
	int cntup = 0, qcnt = 0;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			++qcnt;
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			quest.push_back({{cntup, qcnt - 1}, {l, r}});
		}
		else
		{
			int p, x;
			cin >> p >> x;
			update.push_back({p - 1, x});
			v.push_back(x);
			cntup++;
		}
	}
	vector <int> res(qcnt);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(quest.begin(), quest.end(), cmp);
	for(int i = 0; i < n; i++){
		A[i] = get_id(A[i]);
	}
	for(int i = 0; i < cntup; i++)
	{
		update[i].second = get_id(update[i].second);
	}
	int l = 0, r = -1, now = 0;
	for(int i = 0; i < qcnt; i++)
	{
		while(r < quest[i].second.second)
		{
			add(A[++r]);
		}
		while(l > quest[i].second.first)
		{
			add(A[--l]);
		}
		while(r > quest[i].second.second)
		{
			del(A[r--]);
		}
		while(l < quest[i].second.first)
		{
			del(A[l++]);
		}
		while(now < quest[i].first.first)
		{
			mod(i, ++now);
		}
		while(now > quest[i].first.first)
		{
			mod(i, now--);
		}
		for(int j = 1;;j++)
		{
			if(cnt2[j] == 0)
			{
				res[quest[i].first.second] = j;
				break;
			}
		}
	}
	for(int i = 0; i < qcnt; i++)
	{
		cout << res[i] << "\n";
	}
	return 0;
}
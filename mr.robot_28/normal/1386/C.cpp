#include<bits/stdc++.h>
using namespace std;
vector <int> right1;
vector <int> rang, col, dsu;
vector <pair <int, int> > vec;
int n, m, q;
pair <int, int> pred(int a)
{
	if(a == dsu[a])
	{
		return {dsu[a], 0};
	}
	pair <int, int> t = pred(dsu[a]);
	return {t.first, col[a] ^ t.second};
}
bool flag1 = true;
void unite(int a, int b)
{
	pair <int, int> t1 = pred(a);
	pair <int, int> t2 = pred(b);
	if(t1.first == t2.first && t1.second == t2.second)
	{
		flag1 = false;
	}
	if(t1.first == t2.first)
	{
		return;
	}
	if(rang[t1.first] < rang[t2.first])
	{
		swap(t1, t2);
	}
	if(t1.second == t2.second ^ col[t2.first])
	{
		col[t2.first] ^= 1;
	}
	dsu[t2.first] = t1.first;
	rang[t1.first] += rang[t2.first]; 
}
vector <vector <pair <int, int> > > mass1, mass2, mass3;
vector <pair <int, int> > mass4, mass5,mass6;
void build(int w,int l, int r, int l1, int r1)
{
	mass1[w].resize(r - l + 1);
	mass2[w].resize(r - l + 1);
	mass3[w].resize(r - l + 1);
	if(l == r)
	{
		int r2 = r1;
		bool flag = flag1;
		while(r1 > max(l1, l) && flag1)
		{
			r1--;
			mass4[r1].first = pred(vec[r1].first).first;
			mass5[r1].first = rang[pred(vec[r1].first).first];
			mass6[r1].first = col[pred(vec[r1].first).first];
			mass4[r1].second = pred(vec[r1].second).first;
			mass5[r1].second = rang[pred(vec[r1].second).first];
			mass6[r1].second = col[pred(vec[r1].second).first];
			unite(vec[r1].first, vec[r1].second);
		}
		right1[l] = r1;
		flag1 = flag;
		while(r1 < r2)
		{
			int v = mass4[r1].first;
			dsu[v] = v;
			rang[v] = mass5[r1].first;
			col[v] = mass6[r1].first;
			v = mass4[r1].second;
			dsu[v] = v;
			rang[v] = mass5[r1].second;
			col[v] = mass6[r1].second;
			r1++;
		}
	}
	else
	{
		bool flag = flag1;
		int midd = (r + l) / 2;
		for(int i = l; i <= midd; i++)
		{
			mass1[w][i - l].first = pred(vec[i].first).first;
			mass2[w][i - l].first = rang[pred(vec[i].first).first];
			mass3[w][i - l].first = col[pred(vec[i].first).first];
			mass1[w][i - l].second = pred(vec[i].second).first;
			mass2[w][i - l].second = rang[pred(vec[i].second).first];
			mass3[w][i - l].second = col[pred(vec[i].second).first];
		}
		for(int i = l; i < midd; i++)
		{
			unite(vec[i].first, vec[i].second);
		}
		int r2 = r1;
		while(r1 > max(l1, midd) && flag1)
		{
			r1--;
			mass4[r1].first = pred(vec[r1].first).first;
			mass5[r1].first = rang[pred(vec[r1].first).first];
			mass6[r1].first = col[pred(vec[r1].first).first];
			mass4[r1].second = pred(vec[r1].second).first;
			mass5[r1].second = rang[pred(vec[r1].second).first];
			mass6[r1].second = col[pred(vec[r1].second).first];
			unite(vec[r1].first, vec[r1].second);
		}
		for(int i = r1; i < r2; i++)
		{
			int v = mass4[i].first;
			dsu[v] = v;
			rang[v] = mass5[i].first;
			col[v] = mass6[i].first;
			v = mass4[i].second;
			dsu[v] = v;
			rang[v] = mass5[i].second;
			col[v] = mass6[i].second;
		}
		for(int i = midd - 1; i >= l; i--)
		{
			int v = mass1[w][i - l].first;
			rang[v] = mass2[w][i - l].first;
			col[v] = mass3[w][i - l].first;
			dsu[v] = v;
			v = mass1[w][i - l].second;
			dsu[v] = v;
			rang[v] = mass2[w][i - l].second;
			col[v] = mass3[w][i - l].second;
		}
		flag1 = flag;
		for(int i = r2 - 1; i >= r1; i--){
			mass4[i].first = pred(vec[i].first).first;
			mass5[i].first = rang[pred(vec[i].first).first];
			mass6[i].first = col[pred(vec[i].first).first];
			mass4[i].second = pred(vec[i].second).first;
			mass5[i].second = rang[pred(vec[i].second).first];
			mass6[i].second = col[pred(vec[i].second).first];
			unite(vec[i].first, vec[i].second);
		}
 		build(w * 2, l, midd, l1, r1);
 		for(int i = r1; i < r2; i++)
		{
			int v = mass4[i].first;
			rang[v] = mass5[i].first;
			col[v] = mass6[i].first;
			dsu[v] = v;
			v = mass4[i].second;
			rang[v] = mass5[i].second;
			col[v] = mass6[i].second;
			dsu[v] = v;
		}
		flag1 = flag;
		for(int j = l; j <= midd; j++)
		{
			unite(vec[j].first, vec[j].second);
		}
		build(w * 2 + 1, midd + 1, r, r1, r2);
		for(int i = l; i <= midd; i++)
		{
			int v = mass1[w][i - l].first;
			rang[v] = mass2[w][i - l].first;
			col[v] = mass3[w][i - l].first;
			dsu[v] = v;
			v = mass1[w][i - l].second;
			rang[v] = mass2[w][i - l].second;
			col[v] = mass3[w][i - l].second;
			dsu[v] = v;
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>> n >> m >> q;
    right1.resize(m);
    vec.resize(m);
    mass1.resize(4 * m);
    mass2.resize(4 * m);
    mass3.resize(4 * m);
    rang.resize(n);
    dsu.resize(n);
    mass4.resize(m);
    mass5.resize(m);
    mass6.resize(m);
    col.resize(n);
    for(int i = 0; i < n; i++)
    {
    	dsu[i] = i;
    	rang[i] = 1;
    	col[i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
    	cin >> vec[i].first >> vec[i].second;
    	vec[i].first--;
    	vec[i].second--;
    }
    build(1, 0, m - 1, 0, m);
    while(q--)
    {
    	int l, r;
    	cin >> l >> r;
    	l--;
    	if(right1[l] < r)
    	{
    		cout << "NO\n";
    	}
    	else
    	{
    		cout << "YES\n";
    	}
    }
  	return 0;
}
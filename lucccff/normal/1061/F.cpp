    #include <bits/stdc++.h>
    using namespace std;
     
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #define endl "\n"
    #define int long long
     
    const int N=1e5+5;
     
    int n, k, h, leaf1, leaf2;
    int a[N];
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> v, path;
    map<tuple<int, int, int>, int> store;
     
    int query(int a, int b, int c)
    {
    	tuple<int, int, int> cur=make_tuple(a, b, c);
    	if(store.find(cur)!=store.end())
    		return (store[cur]);
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	string s;
	cin>>s;
	return (store[cur] = ((s=="Yes")));
}
 
int print(int x)
{
    cerr<<x;
	cout<<"! "<<x;
	exit(0);
}
 
int findleaf()
{
	while(true)
	{
		shuffle(a+1, a+n+1, rng);
		int leaf=a[1];
		int random=a[2];
		bool check=1;
		for(int i=3;i<=n;i++)
		{
			check&=(query(random, leaf, a[i])==0);
			if(!check)
				break;
		}
		if(check)
			return leaf;
	}
}
 
int findleaf2()
{
	while(true)
	{
		int count=0;
		shuffle(a+1, a+n+1, rng);
		if(a[1]==leaf1)
			continue;
		int leaf=a[1];
		bool check=1;
		int cnt=0, reqd=2*(h-1) + 1;
		v.clear();
		for(int i=2;i<=n;i++)
		{
			if(a[i]==leaf1)
				continue;
			int current=query(leaf1, a[i], leaf);
			cnt+=current;
			if(current)
				v.push_back(a[i]);
		}
		if(cnt==reqd)
			return leaf;
	}
}
 
void findroot()
{
	path.push_back(leaf1);
	path.push_back(v[0]);
	path.push_back(leaf2);
	for(int i=1;i<v.size();i++)
	{
		vector<int> newpath;
		newpath.push_back(path[0]);
		for(int j=1;j<path.size();j++)
		{
			if(query(path[j-1], v[i], path[j]))
			{
				newpath.push_back(v[i]);
				for(int k=j;k<path.size();k++)
					newpath.push_back(path[k]);
				break;
			}
			else
				newpath.push_back(path[j]);
		}
		path=newpath;
	}
	print(path[h]);
}
 
int32_t main()
{
	cin>>n>>k;
	if(n==1)
	{
	    print(1);
	    return 0;
	}
	int cur=k;
	int nodes=1;
	h=0;
	while(nodes+cur<=n)
	{
		nodes+=cur;
		cur*=k;
		h++;
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	leaf1=findleaf();
	leaf2=findleaf2();
	findroot();
	return 0;
}
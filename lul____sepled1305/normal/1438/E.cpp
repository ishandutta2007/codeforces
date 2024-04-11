#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;

set<pii> st;

void test(vector<int> &v, bool rev)
{
	int i,j, n = v.size();
	for(i=0;i<n;i++)
	{
		int sum = 0;
		for(j=i+1;j<n-1;j++)
		{
			sum += v[j];
			if(sum > 2*v[i])
				break;
			if(sum == (v[i]^v[j+1]))
			{
				//cout<<"This is debug part: "<<rev<<' '<<sum<<' '<<v[i]<<' '<<v[j+1]<<endl;
				if(rev)
				{
					if(!st.count({n-2-j,n-1-i}))
						st.insert({n-2-j,n-1-i});
				}
				else
				{
					if(!st.count({i,j+1}))
						st.insert({i,j+1});
				}
			}
		}
	}
}

main() {
	int n,i,a;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	test(v,false);
	reverse(v.begin(),v.end());
	test(v,true);
	cout<<st.size()<<endl;
	return 0;
}
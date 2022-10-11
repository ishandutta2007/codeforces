#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> v;
    int n,i,a,ans=-1,res=0;
    cin >> n;
    for (i=0;i<n;i++)
    {
    	cin >> a;
    	v.push_back(a);
	}
	while (v.size())
	{
		for (i=0;i<v.size() && v.size();i++)
		{
			if (res>=v[i])
			{
				res++;
				v.erase(v.begin()+i);
				i--;
			}
		}
		ans++;
		if (v.size())
		{
			for (i=v.size()-1;i>=0 && v.size();i--)
			{
				if (res>=v[i])
				{
					res++;
					v.erase(v.begin()+i);
				}
			}
			ans++;
		}
	}
	cout << ans;
}
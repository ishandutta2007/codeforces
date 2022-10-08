#include<iostream>
#include<vector>
typedef long long ll;

using namespace std;

bool isPossibleToMakeCookies(ll numOfCookies, ll k, vector<ll> &A, vector<ll> &B)
{
	int n = A.size();
	ll requiredGram = 0LL;
	for(int i=0; i<n; ++i)
	{
		requiredGram += max(0LL, numOfCookies*A[i]*1LL - B[i]);
		if(k<requiredGram)
			return false;

		//k = k - requiredGram;
	}


	return true;
}

int getMaxCookies(ll min_, ll max_, long k, vector<ll> &A, vector<ll> &B)
{
	int maxCookies = 0;

	if(min_ > max_)
		return maxCookies;

	while(min_ <= max_)
	{
		ll numOfCookies = (min_+max_)>>1;
		bool valid = isPossibleToMakeCookies(numOfCookies, k, A, B);
		// cout<<numOfCookies<<" "<<valid<<" "<<min_<<" "<<max_<<endl;
		if(valid)
		{
			maxCookies = numOfCookies;
			min_ = numOfCookies + 1;
		}
		else
			max_ = numOfCookies - 1;


	}

	return maxCookies;
}

int solve()
{
	ll n, k;

	cin>>n>>k;

	vector<ll> A(n), B(n);

	for(int i=0; i<n; ++i)
		cin>>A[i];

	for(int i=0; i<n; ++i)
		cin>>B[i];

	if(n==1)
		return ((k+B[0])/A[0]);

	return getMaxCookies(1, 1e9+k, k, A, B);
}

int main()
{

	cout<<solve();
	return 0;
}
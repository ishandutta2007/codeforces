#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint Q;

llint get(llint k, llint n)
{
	llint ret = 0, mul = 9;
	for(int i = 1; i < k; i++){
		ret += i * mul * n;
		mul *= 10;
	}
	ret += n*(n+1)/2 * k;
	return ret;
}

llint count(llint n)
{
	llint keta = 0;
	for(llint x = n; x; x/=10) keta++;
	
	llint ret = 0, mul = 9, mul2 = 1;
	for(int i = 1; i < keta; i++){
		ret += get(i, mul);
		mul *= 10, mul2 *= 10;
	}
	ret += get(keta, n-mul2+1);
	return ret;
}

llint count2(llint n)
{
	llint keta = 0;
	for(llint x = n; x; x/=10) keta++;
	
	llint ret = 0, mul = 9, mul2 = 1;
	for(int i = 1; i < keta; i++){
		ret += i*mul;
		mul *= 10, mul2 *= 10;
	}
	ret += keta * (n-mul2+1);
	return ret;
}

llint getketa(llint x, llint p)
{
	vector<llint> vec;
	for(; x; x/=10) vec.push_back(x%10);
	reverse(vec.begin(), vec.end());
	return vec[p-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	//for(int i = 1; i <= 100000; i++) cout << i << ":" << count(i) << endl;
	
	llint x;
	for(int q = 0; q < Q; q++){
		cin >> x;
		
		llint ub = 50000, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(count(mid) >= x) ub = mid;
			else lb = mid;
		}
		llint rem = x - count(lb);
		
		ub = 50000, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(count2(mid) >= rem) ub = mid;
			else lb = mid;
		}
		rem -= count2(lb);
		
		cout << getketa(ub, rem) << endl;
	}
	
	return 0;
}
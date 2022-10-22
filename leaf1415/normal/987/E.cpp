#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[1000005];

llint bit[1000005];
llint sum(llint i)
{
	llint ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i & (-i);
	}
	return ret;
}
void add(llint i, llint x)
{
	while(i <= n){
		bit[i] += x;
		i += i & (-i);
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint inv = 0;
	for(int i = 1; i <= n; i++){
		inv += (i-1) - sum(a[i]);
		add(a[i], 1);
	}
	
	if(n % 2){
		if(inv % 2) cout << "Petr" << endl;
		else cout << "Um_nik" << endl;
	}
	else{
		if(inv % 2) cout << "Um_nik" << endl;
		else cout << "Petr" << endl;
	}
	
	return 0;
}
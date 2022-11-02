# include <iostream>
# include <cstdio>
using namespace std;

int gcd(int a,int b) {
	for(int t; b; t=a, a=b, b=t%b);
	return a;
}

int get(int &t) {
	int ans = 0;
	while(t%2==0)t=t/2,ans++;
	while(t%3==0)t=t/3,ans++;
	while(t%5==0)t=t/5,ans++;
	return ans;
}
int main()
{
	int a, b, t; 
	cin >> a >> b;
	t = gcd(a,b);
	a = a / t, b = b / t;
	int ans = get(a) + get(b);
	if(a==1 && b==1) 
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
# include <iostream>

long long C[100][100];
long long ans = 0;
int main()
{
	long long n, t; 
	std::cin >> n >> t; n++;
	if(t & (t-1))  
		return std::cout<<0<<std::endl, 0;
	int d = 0; if(t==1)ans--;
	while(t)d++, t=t>>1;

	C[0][0]=1;
	for(int i=1;i<=62;i++)C[i][0]=1;
	for(int i=1;i<=62;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];

	for(int i=62;i>=0;i--)
		if((n>>i)&1) if(d>=0) ans += C[i][d--];
	if(d==0)ans++;
	std::cout<<ans<<std::endl;
}
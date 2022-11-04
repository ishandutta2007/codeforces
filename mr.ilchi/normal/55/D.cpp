/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>

using namespace std;

const int MAXD= 18+2;
const int BASE= 5*7*8*9;
const int Size= 48;

int t;
int Pow[MAXD], pri[Size], par[BASE+5];
long long beg, fin;
long long dp[MAXD][Size+2][BASE+2];

inline int gcd (int x, int y){
	return (x && y) ? gcd (y%x,x) : x+y;
}
/*****************************************/
inline void init (){
	Pow[0]= 1;
	for (int i= 1;i< MAXD;i ++)
		Pow[i]= (Pow[i-1]*10)%BASE;
	int len= 0;
	for (int i= 1;i<= BASE;i ++){
		if ((BASE%i)== 0){
			par[i]= len;
			pri[len++]= i;
		}
	}
}
/****************************************/
inline void setDyn (){
	for (int i= 0;i< 10;i ++)
		dp[1][max (0, i-1)][i]= 1;

	for (int i= 2;i<= 18;i ++){
		for (int j= 0;j< Size;j ++){ 
			for (int z= 1;z<= 9;z ++){
				int lcm= par[pri[j]*z/gcd(pri[j],z)], tmp= (z*Pow[i-1])%BASE;
				for (int t= 0;t< BASE;t ++)
					dp[i][lcm][t]+= dp[i-1][j][(t-tmp+BASE)%BASE];
			}
		}
		for (int j= 0;j< Size;j ++)
			for (int z= 0;z< BASE;z ++)
				dp[i][j][z]+= dp[i-1][j][z];
	} 
}
/****************************************/
inline long long check (long long v){
	if (v== 0)
		return 0;
	int len= 0;
	int dig[MAXD];
	while (v!= 0){
		dig[len++]= v%10;
		v/=10;
	}	
	int lcm= 1, cur= 0;
	long long res= 0;
	for (int i= len-1;i>= 1;i --){
		int v= dig[i];
		for (int j= 0;j< v;j ++){
			int tmp_cur= ((cur*10+j)*Pow[i])%BASE;
			int tmp_lcm= lcm*max(1,j)/gcd(lcm,max(1,j));
			for (int z= 0;z< Size;z ++){
				int tmp2_lcm= tmp_lcm*pri[z]/gcd(pri[z],tmp_lcm);
				int temp= 0;
				while (temp< BASE){
					res += dp[i][z][(temp-tmp_cur+BASE)%BASE]; 
					temp+= tmp2_lcm;
				}
			}
		}
		cur= (cur*10+v)%BASE;
		lcm= lcm*max(v,1)/gcd(lcm,max(v,1));
	}
	for (int i= 0;i<= dig[0];i ++){
		int tmp_cur= (cur*10+i)%BASE;
		int tmp_lcm= lcm*max(1,i)/gcd(lcm,max(1,i));
		if ((tmp_cur%tmp_lcm)== 0)
			res ++;
	}
	res --;
	return res;
}
/****************************************/
int main (){
	init ();
	setDyn ();
	cin >> t;
	while (t){
		cin >> beg >> fin;
		cout << check (fin)-check(beg-1) << endl;
		t --;
	}
	return 0;
}
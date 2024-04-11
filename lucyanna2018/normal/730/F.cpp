#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, coin, money;
int a[5555];
int expire[5555];
vector<int> fre, locked[11];
int ans[5555];

void add_fre(int amount, int id) {
	for(int i=0;i<amount;i++)
		fre.push_back(id);
}

void try_spend_fre(int &amount) {
	while(amount && fre.size()) {
		ans[fre.back()] ++;
		amount --;
		fre.pop_back();
	}
}
void try_spend(int &amount) {
	try_spend_fre(amount);
	for(int i=10;i>0 && amount;i--)
		while(amount && locked[i].size()) {
			amount --;
			int id = locked[i].back();
			locked[i].pop_back();
			add_fre(i, id);
			try_spend_fre(amount);
		}
}

int main() {
	scanf("%d%d", &n, &coin);
	money = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		// ..
		int today_coin = a[i] / 10;
		expire[i+1] = today_coin; // fori+1
		
		money += a[i];
	}
	
	for(int i=n;i>0;i--) {
		int today_discount = a[i]/2;
		
		// ifi+1
		// 
		int lock_fre = expire[i+1];
		
		// 
		int today_fre = min(a[i]%10, today_discount);
		add_fre(today_fre, i); 
		today_discount -= today_fre;
		
		// 1
		for(int j=today_discount / 10; j>0; j--)
			if (lock_fre) {
				lock_fre --;
				add_fre(10, i);
			} else locked[10].push_back(i);
		today_discount %= 10;
		
		if (today_discount) {
			if (lock_fre) add_fre(today_discount, i);
			else locked[today_discount].push_back(i);
		}
		
		try_spend(expire[i]); // 
	}
	try_spend(coin);
	for(int i=1;i<=n;i++)
		money -= ans[i];
	printf("%d\n", money);
	for(int i=1;i<=n;i++)
		printf("%d%c", ans[i], i<n ? ' ' : '\n');
	
	return 0;
}
#include <iostream>
#include <string>
#include <queue>
#define llint long long

using namespace std;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

struct DoubleQueueMedian{
	priority_queue<llint> leftQ;
	priority_queue<llint, vector<llint>, greater<llint> > rightQ;
	llint lsum, rsum, lnum, rnum;
	
	DoubleQueueMedian(){
		init();
	}
	void init(){
		while(leftQ.size()) leftQ.pop();
		while(rightQ.size()) rightQ.pop();
		lsum = rsum = lnum = rnum = 0;
	}
	void add(llint x)
	{
		if(leftQ.size() == 0 || leftQ.top() >= x){
			leftQ.push(x);
			lsum += x;
			if(leftQ.size() >= rightQ.size()+2){
				rightQ.push(leftQ.top());
				rsum += leftQ.top();
				lsum -= leftQ.top();
				leftQ.pop();
			}
		}
		else{
			rightQ.push(x);
			rsum += x;
			if(rightQ.size() >= leftQ.size()+1){
				leftQ.push(rightQ.top());
				lsum += rightQ.top();
				rsum -= rightQ.top();
				rightQ.pop();
			}
		}
		lnum = (llint)leftQ.size(), rnum = (llint)rightQ.size();
	}
	llint getMedian(){
		return leftQ.top();
	}
	llint getMoment(){
		llint x = getMedian();
		llint ret = x * lnum - lsum;
		ret += rsum - x * rnum;
		return ret;
	}
};

llint n;
llint p[200005], pinv[200005];
llint inv[200005];
BIT bit(200005);
DoubleQueueMedian dqm;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) pinv[p[i]] = i;
	
	llint sum = 0;
	for(int i = 1; i <= n; i++){
		sum += (i-1) - bit.query(pinv[i]);
		inv[i] = sum;
		bit.add(pinv[i], 1);
	}
	
	for(int i = 1; i <= n; i++){
		dqm.add(pinv[i]);
		llint ans = dqm.getMoment();
		
		llint lnum = dqm.lnum-1, rnum = dqm.rnum;
		ans -= lnum*(lnum+1)/2, ans -= rnum*(rnum+1)/2;
		ans += inv[i];
		
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}
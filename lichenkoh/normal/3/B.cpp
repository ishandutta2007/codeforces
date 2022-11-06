#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

vector<long long> instr;

int cmp (const void * a, const void * b)
{
  if ((*(long long**)a)[0] > (*(long long**)b)[0]) return 1;
  if ((*(long long**)a)[0] < (*(long long**)b)[0]) return -1;
  return 0;
}

//Greedy algorithm that steps by 2 each time
long long calc(long long v,long long **k,long long **c, long long numk, long long numc) {
	// Base cases are 0,1,3
	if (v == 0) {
		return 0;
	}

	if (v % 2 == 1) {
		if (numk > 0) {
			instr.push_back(k[numk-1][1]);
			return k[numk-1][0] + + calc(v-1,k,c, numk-1, numc);;
		}
		else {
			return calc(v-1,k,c, numk-1, numc);;
		}
	}
	/*
	if (v == 1) {
		if (numk > 0) {
			instr.push_back(k[numk-1][1]);
			return k[numk-1][0];
		}
		else {
			return 0;
		}
	}
	*/
	/*
	if (v == 3) {
		//Try 1-1-1 and 2-1 configuration
		long long sum111 = 0;
		for (long long i = numk-1; i >= numk-3 && i >= 0; i--) {
			sum111 += k[i][0];
		}
		long long sum21 = 0;
		if (numc > 0) {
			cout << "Hit:" << c[numc-1][0] << endl;
			sum21 += c[numc-1][0];
		}
		if (numk > 0) {
			cout << "Hit2:" << k[numk-1][0] << endl;
			sum21 += k[numk-1][0];
		}
		if (sum111 > sum21) {
			for (long long i = numk-1; i >= numk-3 && i >= 0; i--) {
				instr.push_back(k[i][1]);
			}
			return sum111;
		}
		else {
			if (numc > 0) {
				instr.push_back(c[numc-1][1]);
			}
			if (numk > 0) {
				instr.push_back(k[numk-1][1]);
			}
			return sum21;
		}
	}
	*/
	else {
			//Try 1-1 and 2 configuration. Prioritize the 2 configuration over the 1-1 config.
			if (numk == 0 && numc == 0) { return 0; }
			long long sum11 = 0;
			if (numk > 1) {
				sum11 = k[numk-1][0] + k[numk-2][0];
			}
			if (numk == 1) {
				sum11 = k[numk-1][0];
			}
			long long sum2 = 0;
			if (numc > 0) {
				sum2 = c[numc-1][0];
			}
			if (sum2 >= sum11) { // Prioritize the 2 configuration
				if (numc > 0) {
					//cout << "DEBUG:" << ci[numc-1] << " " << c[numc-1] << endl;
					instr.push_back(c[numc-1][1]);
					return c[numc-1][0] + calc(v-2,k,c, numk, numc-1);
				}
				else {
					return 0;
				}
			}
			else {
				if (numk > 1) {
					instr.push_back(k[numk-1][1]);
					instr.push_back(k[numk-2][1]);
					return sum11 + calc(v-2,k,c, numk-2, numc);
				}
				if (numk == 1) {
					instr.push_back(k[numk-1][1]);
					return sum11 + calc(v-1,k,c, numk-1, numc);
				}
				if (numk == 0) {
					return 0;
				}
			}
	}
	assert(false);
	return -9999;
}

int main()
{
	long long n;
	long long v;
	cin >> n;
	cin >> v;
	long long **k = new long long*[n];
	long long **c = new long long*[n];
	for (long long i = 0; i < n; i++) {
		k[i] = new long long[2];
		c[i] = new long long[2];
	}
	long long numk = 0;
	long long numc = 0;
	for (long long i = 0; i < n; i++) {
		long long t;
		cin >> t;
		assert(t==1 || t==2);
		if (t == 1) {
			cin>> k[numk][0];
			k[numk][1] = i+1;
			numk++;
		}
		else {
			cin>>c[numc][0];
			//cout << i+1 <<  endl;
			c[numc][1] = i+1;
			numc++;
		}
	}
	// Sort in INCREASING order. Then we pick off the last element one by one.
	qsort(k,numk,sizeof(long long*),cmp);
	qsort(c,numc,sizeof(long long*),cmp);
	long long ans = calc(v,k,c,numk,numc);
	cout << ans << endl;
	for (vector<long long>::iterator it = instr.begin(); it != instr.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
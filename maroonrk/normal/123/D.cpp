#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)

const int N = 1000001;
int bucket[N];

template <class T>
void CreateBeginBucket(T* data, int size, int maxVal){
	REP(i, maxVal + 1) bucket[i] = 0;
	REP(i, size) bucket[data[i]]++;
	int sum = 0;
	REP(i, maxVal + 1){ bucket[i] += sum; swap(bucket[i], sum); }
}

template <class T>
void CreateEndBucket(T* data, int size, int maxVal){
	REP(i, maxVal + 1) bucket[i] = 0;
	REP(i, size) bucket[data[i]]++;
	int sum = 0;
	REP(i, maxVal + 1){ sum += bucket[i]; bucket[i] = sum; }
}

template<class T>
void InducedSort(T* data, int size, int* SA, int maxVal, bool* isL){
	CreateBeginBucket(data, size, maxVal);
	REP(i, size) if (SA[i] > 0 && isL[SA[i] - 1]) SA[bucket[data[SA[i] - 1]]++] = SA[i] - 1;
}

template<class T>
void InvertInducedSort(T* data, int size, int* SA, int maxVal, bool* isL){
	CreateEndBucket(data, size, maxVal);
	for (int i = size - 1; i >= 0; --i) if (SA[i] > 0 && !isL[SA[i] - 1]) SA[--bucket[data[SA[i] - 1]]] = SA[i] - 1;
}

template <class T>
void DBGOUT(T* sa, int size){
	REP(i, size) printf("%d ", int(sa[i]));
	printf("\n");
}

template<class T>
void SA_IS(T* data, int size, int* SA, int maxVal, bool* isL){
	REP(i, size) SA[i] = -1;
#define isLMS(x) (x>0 && isL[x-1] && !isL[x])
	isL[size - 1] = false;
	for (int i = size - 2; i >= 0; i--) isL[i] = data[i] > data[i + 1] || (data[i] == data[i + 1] && isL[i + 1]);
	CreateEndBucket(data, size, maxVal);
	FOR(i, 1, size) if (isLMS(i)) SA[--bucket[data[i]]] = i;
	InducedSort(data, size, SA, maxVal, isL);
	InvertInducedSort(data, size, SA, maxVal, isL);

	int c = 0;
	REP(i, size) if (isLMS(SA[i])) SA[c++] = SA[i];
	FOR(i, c, size) SA[i] = -1;

	int idx = -1;
	int prev = -1;
	REP(i, c){
		bool diff = false;
		REP(d, size){
			if (prev == -1 || data[SA[i] + d] != data[prev + d] || isL[SA[i] + d] != isL[prev + d]){
				diff = true;
				break;
			}
			else if (d > 0 && isLMS(SA[i] + d)) break;
		}
		if (diff){ idx++; prev = SA[i]; }
		SA[c + SA[i] / 2] = idx;
	}
	int j = size;
	for (int i = size - 1; i >= c; i--) if (SA[i] >= 0) SA[--j] = SA[i];

	int* nxdata = SA + size - c;
	int* nxsa = SA;
	if (c == idx + 1) REP(i, c) nxsa[nxdata[i]] = i;
	else SA_IS(nxdata, c, nxsa, idx, isL + size);

	j = c;
	for (int i = size - 1; i >= 1; i--) if (isLMS(i)) nxdata[--j] = i;
	REP(i, c) nxsa[i] = nxdata[nxsa[i]];
	FOR(i, c, size) SA[i] = -1;
	CreateEndBucket(data, size, maxVal);
	for (int i = c - 1; i >= 0; i--) swap(nxsa[i], SA[--bucket[data[nxsa[i]]]]);
	InducedSort(data, size, SA, maxVal, isL);
	InvertInducedSort(data, size, SA, maxVal, isL);
}

bool isLPool[N * 2];
void SA_IS(unsigned char* input, int size, int* SA){
	int mv = 0;
	REP(i, size) if (mv < input[i]) mv = input[i];
	SA_IS(input, size, SA, mv, isLPool);
}

int lcp[N + 1];
int invertSA[N];
void CreateLCP(unsigned char* data, int size, int* SA){
	lcp[0] = -1;
	REP(i, size) invertSA[SA[i]] = i;
	int prev = 0;
	REP(i, size){
		if (invertSA[i] > 0){
			while (data[i + prev] == data[SA[invertSA[i] - 1] + prev]){
				++prev;
				if (i + prev >= size || SA[invertSA[i] - 1] + prev >= size)
					break;
			}
			lcp[invertSA[i]] = prev;
		}
		prev = max(prev - 1, 0);
	}
}

unsigned char str[N];
int indices[N];
int main(){
	scanf("%s", str);
	int n = strlen((const char*)str) + 1;
	SA_IS(str, n, indices);
	CreateLCP(str, n, indices);
	lcp[n] = 0;
	struct e
	{
		int lcp;
		int idx;
	};
	static e estack[N + 1];
	int sc = 0;
	long long ans = (long long)(n) * (n-1) / 2;
	REP(l, n + 1){
		while (sc > 1){
			if (estack[sc - 1].lcp > lcp[l]){
				if (estack[sc - 2].lcp > lcp[l]){
					ans += (long long)(l - estack[sc - 1].idx) * (l - estack[sc - 1].idx + 1) / 2 * (estack[sc - 1].lcp - estack[sc - 2].lcp);
					sc--;
				}
				else{
					ans += (long long)(l - estack[sc - 1].idx) * (l - estack[sc - 1].idx + 1) / 2 * (estack[sc - 1].lcp - lcp[l]);
					estack[sc - 1].lcp = lcp[l];
				}
			}
			else break;
		}
		if (sc == 0 || estack[sc - 1].lcp < lcp[l])
			estack[sc++] = { lcp[l], l };
	}
	printf("%I64d\n", ans);
}
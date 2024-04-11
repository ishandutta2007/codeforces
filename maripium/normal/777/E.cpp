/*Coi choi game l cch h?c, ?c d? chuyn Tin v ti?ng Anh c?a 4 tru?ng hng d?u H N?i, trong d m?t tru?ng c?p h?c b?ng.
N? sinh d? th? khoa l?p 10 x? Ngh?

L c?u h?c sinh khng qu n?i tr?i c?a l?p 9A2 tru?ng THCS L Qu n (Nam T? Lim, H N?i), Nguy?n H?u ?c v?a d? l?p Tin c?a 3 tru?ng THPT chuyn H N?i - Amsterdam, THPT chuyn ?i h?c Su ph?m, THPT chuyn Khoa h?c t? nhin (?i h?c Qu?c gia H N?i).

Ngoi ra, ?c thi thm chuyn Anh c?a THPT chuyn Ngo?i ng? (?i h?c Qu?c gia H N?i) v trng tuy?n. Em cn vo top 20 th sinh xu?t s?c c?a THPT chuyn ?i h?c Su ph?m, du?c nh?n h?c b?ng c?a tru?ng. ? m?i l?n thi, ?c d?u th?a t? 1 d?n 3 di?m.

K?t qu? ny khi?n khng ch? gio vin, ph? huynh m chnh ?c cung b?t ng?. Em thi chuyn Su ph?m theo l?i d? ngh? c?a m? d? l?y kinh nghi?m, nhung l?i d?t h?c b?ng v ch? thi chuyn Anh d? bi?t kh? nang mnh d?n du, ?c ni.
Coi choi game l cch h?c, ?c d? chuyn Tin v ti?ng Anh c?a 4 tru?ng hng d?u H N?i, trong d m?t tru?ng c?p h?c b?ng.
N? sinh d? th? khoa l?p 10 x? Ngh?

L c?u h?c sinh khng qu n?i tr?i c?a l?p 9A2 tru?ng THCS L Qu n (Nam T? Lim, H N?i), Nguy?n H?u ?c v?a d? l?p Tin c?a 3 tru?ng THPT chuyn H N?i - Amsterdam, THPT chuyn ?i h?c Su ph?m, THPT chuyn Khoa h?c t? nhin (?i h?c Qu?c gia H N?i).

Ngoi ra, ?c thi thm chuyn Anh c?a THPT chuyn Ngo?i ng? (?i h?c Qu?c gia H N?i) v trng tuy?n. Em cn vo top 20 th sinh xu?t s?c c?a THPT chuyn ?i h?c Su ph?m, du?c nh?n h?c b?ng c?a tru?ng. ? m?i l?n thi, ?c d?u th?a t? 1 d?n 3 di?m.

K?t qu? ny khi?n khng ch? gio vin, ph? huynh m chnh ?c cung b?t ng?. Em thi chuyn Su ph?m theo l?i d? ngh? c?a m? d? l?y kinh nghi?m, nhung l?i d?t h?c b?ng v ch? thi chuyn Anh d? bi?t kh? nang mnh d?n du, ?c ni.
?c th?ng th?n by t? quan di?m khng thch h?c thm. H?i l?p 8, b? m? cho em h?c thm qu nhi?u nn b? ng ngo?i m?ng v b?t cho em ngh?, ?c k? v cho bi?t ? l?p h?c thm, th?y ra d?, h?c sinh chua k?p suy nghi d dua lun l?i gi?i. i?u d khi?n ?c khng d?ng l?i du?c g trong d?u.

C Bi Th? Kim Oanh, gio vin ch? nhi?m c?p 2, dnh gi ?c c tu duy t?t. ?c thng minh v c tnh yu d?c bi?t v?i Ton. V mn Van lun ko di?m xu?ng trong su?t qu trnh h?c t?p nn th?y c r?t b?t ng? v?i k?t qu? thi c?a em, c Oanh chia s? v thng tin thm ?c l h?c sinh c thnh tch t?t nh?t tru?ng THCS L Qu n trong k? tuy?n sinh v?a qua.

C ni?m dam m l?n v?i Ton h?c nhung ?c quy?t d?nh ch?n thi v h?c chuyn Tin tru?ng THPT chuyn Khoa h?c t? nhin v u?c mo tr? thnh l?p trnh vin v "du?c choi game nhi?u hon".

T? nam l?p 6, em du?c ti?p xc v?i gi?ng vin ?i h?c Khoa h?c t? nhin. Th?y ni r?ng em r?t h?p v?i Tin h?c v k? cu chuy?n v? nh?ng ngn ng? l?p trnh nhu C++ khi?n em thch th, ?c gi?i thch. D chua h?c Tin chuyn su nhung em v?n thu?ng xuyn vo cc forum tin h?c d? d?c hng ngy.

?c hy v?ng c co h?i tham gia k? thi Olympic Tin h?c qu?c t? trong th?i gian t?i v nh?n du?c su?t h?c b?ng du h?c trong tuong lai. 
*/
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int  N = 1e5 + 6;
typedef pair<int,int> Pair;
typedef pair<int,Pair> Triple;

priority_queue<Triple> pq;
priority_queue<Triple, vector<Triple>, greater<Triple> > pq2;

int n;
signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;++i) {
		int a, b, h; cin >> a >> b >> h;
		pq.push(Triple(b, Pair(a, h)));
	} 
	
	int ans = 0;
	int cur = 0;
	while(!pq.empty()) {
		Triple x = pq.top(); pq.pop();
		while(!pq2.empty()) {
			if (x.fi > pq2.top().se.fi) break;
			cur -= pq2.top().se.se;
			pq2.pop();
		}
		pq2.push(x);
		cur += x.se.se;
		ans = max(ans, cur);
	}
	
	cout << ans << endl;
}
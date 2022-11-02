
from datetime import datetime, timedelta
import time

s, m, h, day, dat, mon = map(int, raw_input().split())
T = input()

def match(dt):
	if s != -1 and dt.second != s:
		return False
	if m != -1 and dt.minute != m:
		return False
	if h != -1 and dt.hour != h:
		return False
	if mon != -1 and dt.month != mon:
		return False
	if day != -1 and dt.weekday()+1 == day:
		return True
	if dat != -1 and dt.day == dat:
		return True
	if day == -1 and dat == -1:
		return True
	return False

def to_timestamp(dt):
	return int((dt - datetime(1970,1,1)).total_seconds())

def get_next(ts):
	dt = datetime.utcfromtimestamp(ts)
	tmp = dt
	while True:
		tmp += timedelta(seconds=1)
		while True:
			if mon != -1 and tmp.month != mon:
				if tmp.month > mon:
					tmp += timedelta(days=360)
				tmp = tmp.replace(month=mon, day=1)
				tmp = tmp.replace(hour=0, minute=0, second=0)
			elif dat != -1 and tmp.day != dat and day == -1:
				if tmp.day < 28:
					if tmp.day > dat:
						tmp += timedelta(days=31)
					tmp = tmp.replace(day=min(dat, 28))
				else:
					tmp += timedelta(days=1)
				tmp = tmp.replace(hour=0, minute=0, second=0)
			elif day != -1 and tmp.weekday()+1 != day and (dat == -1 or tmp.day != dat):
				tmp += timedelta(days=1)
				tmp = tmp.replace(hour=0, minute=0, second=0)
			elif h != -1 and tmp.hour != h:
				if tmp.hour > h:
					tmp += timedelta(days=1)
				tmp = tmp.replace(hour=h)
				tmp = tmp.replace(minute=0, second=0)
			elif m != -1 and tmp.minute != m:
				if tmp.minute > m:
					tmp += timedelta(hours=1)
				tmp = tmp.replace(minute=m)
				tmp = tmp.replace(second=0)
			elif s != -1 and tmp.second != s:
				if tmp.second > s:
					tmp += timedelta(minutes=1)
				tmp = tmp.replace(second=s)
			else:
				break
		if match(tmp):
			return to_timestamp(tmp)
	return tmp

ttt = 12622780800
for ts in xrange(T):
	ts = input()
	delta = ts / ttt * ttt
	ts %= ttt
	print get_next(ts)+delta
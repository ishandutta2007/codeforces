import sys, random

normal = 'no,great!,don\'t think so,not bad,cool,don\'t touch me,great'.split(',')
grumpy = 'no,no way,are you serious?,don\'t even,terrible,go die in a hole,worse,are you serious,are you serius'.split(',')
p = [i for i in range(10)]
random.shuffle(p)
for i in p:
    print(i)
    sys.stdout.flush()
    s = input()
    if (s in normal) and (s in grumpy):
        continue
    if s in normal:
        print('normal')
        break
    else:
        print('grumpy')
        break
sys.stdout.flush()
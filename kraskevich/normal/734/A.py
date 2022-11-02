_, s = input(), input()
cnt_a = s.count('A')
cnt_d = s.count('D')
if cnt_a > cnt_d:
    print('Anton')
elif cnt_a < cnt_d:
    print('Danik')
else:
    print('Friendship')
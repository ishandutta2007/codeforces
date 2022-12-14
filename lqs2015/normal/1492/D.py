a, b, k = map(int,input().split(' '))
b -= 1
if k == 0 :
    print("Yes")
    print('1' * (b + 1) + '0' * a)
    print('1' * (b + 1) + '0' * a)
else:
    if a + b <= k :
        print("No")
    else:
        if a == 0 or b == 0:
            print("No")
        else :
            print("Yes")
            if a + b - k <= a :
                print('1' * (b + 1) + '0' * a)
                print('10' + '1' * (b - 1) + '0' * (k - b) + '1' + '0' * (a + b - k - 1))
            else :
                print('1' * (k + 1) + '0' + '1' * (b - k) + '0' * (a - 1))
                print('10' + '1' * b + '0' * (a - 1))
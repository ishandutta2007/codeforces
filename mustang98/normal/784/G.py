a = input()
b = int(eval(a))
res = '+' * 48;
if b >= 200:
    res += "++.--";
    b -= 200;
elif b >= 100:
    res += "+.-";
    b -= 100;
k = b // 10
b %= 10
if k > 0:
    res += ("+" * k + '.' + '-' * k)
res += ('+' * b + '.')
    
print(res)
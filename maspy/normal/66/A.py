x = int(input())

if -128 <= x <= 127:
    print("byte")
elif -32768 <= x <= 32767:
    print("short")
elif -2147483648 <= x <= 2147483647:
    print("int")
elif -9223372036854775808 <= x <= 9223372036854775807:
    print("long")
else:
    print("BigInteger")
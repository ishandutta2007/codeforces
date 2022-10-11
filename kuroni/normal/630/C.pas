uses math;
var n, i: longint;
    ans: int64;
begin
    read(n);
    ans := 0;
    for i := 1 to n do ans := ans + round(IntPower(2,i));
    write(ans);
end.
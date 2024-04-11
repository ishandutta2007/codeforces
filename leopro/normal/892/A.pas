program Project1;

var
  n, i: LongInt;
  a, b: array [0..100000] of LongInt;
  V: Int64;
  max1, max2, temp: LongInt;

begin
  ReadLn(n);
  V := 0; max1 := 0; max2 := 0;
  For i := 0 to n-1 do
  begin
    If i < n-1 then Read(a[i]) else ReadLn(a[i]);
    V := V + a[i];
  end;
  For i := 0 to n-1 do
  begin
    If i < n-1 then Read(b[i]) else ReadLn(b[i]);
    If max1 > max2 then
    begin
      temp := max1;
      max1 := max2;
      max2 := temp;
    end;
    If b[i] > max1 then max1 := b[i];
  end;
  If V > max1 + max2 then WriteLn('NO') else WriteLn('YES');  readln;
end.
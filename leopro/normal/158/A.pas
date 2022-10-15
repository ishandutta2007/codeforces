program Project1;

var
  n, i, k, counter: SmallInt;
  a: array [1..50] of SmallInt;

begin
  Read(n); ReadLn(k);
  For i := 1 to n do If i < n then Read(a[i]) else ReadLn(a[i]);
  If a[k] > 0 then
  begin
    counter:=k-1;
    For i := k to n do If a[i] = a[k] then counter:=counter+1;
  end else
  begin
    counter:=0;
    For i := 1 to k-1 do If a[i] > 0 then counter:=counter+1;
  end;
  WriteLn(counter);
end.
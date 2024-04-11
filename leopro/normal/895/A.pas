program Project1;

var
  n, beginning, ending, i, j, k, sum, CloseTo180Sum: LongInt;
  a: array [0..360] of LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

procedure Change(var a, b: LongInt);
var
  tmp: LongInt;
begin
  tmp := b;
  b := a;
  a := tmp;
end;

begin
  ReadLn(n);
  ReadArray(a, N);
  CloseTo180Sum := 0;
  For j := 0 to N-1 do
  begin
    For k := 0 to N-1 do
    begin
      beginning := j;
      ending := k;
      If beginning > ending then Change(beginning, ending);
      sum := 0;
      For i := beginning to ending do
      begin
        sum := sum + a[i];
      end;
      If abs(sum - 180) < abs(CloseTo180Sum - 180) then CloseTo180Sum := sum;
    end;
  end;
  WriteLn(abs(CloseTo180Sum-180)*2); 
end.
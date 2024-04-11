uses
Math;

var
  n, m, i, sum, zeros, j:Int32;
  a: array [1..100000] of Int32;

begin
  ReadLn(m, n);
  For i := 1 to m do a[i] := 0;
  zeros := m;
  For j := 1 to n do begin
    Read(sum);
    If a[sum] = 0 then zeros -= 1;
    a[sum] += 1;
    If zeros = 0 then
    begin
      For i := 1 to m do
      begin
        a[i] -= 1;
        If a[i] = 0 then
        zeros += 1;
      end;
      Write('1');
      Continue;
    end;
    Write('0');
  end;
end.
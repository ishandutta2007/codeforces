program Project1;

var
  n, i, module: LongInt;
  //a: array [0..23] of LongInt;
  Dif0: Boolean;
  //Months: array [1..60] of LongInt;

begin
  ReadLn(n);
  module:=n mod 4;
  Case module of
  0:
  begin
    WriteLn(0);
    Write(n div 2, ' ');
    For i := 1 to n do
    begin
      Case i mod 4 of
      0: If i = n then WriteLn(i) else Write(i, ' ');
      1: Write(i, ' ');
      end;
    end;
  end;
  1:
  begin
    WriteLn(1);
    Write(n div 2 + 1, ' ');
    For i := 1 to n do
    begin
      Case i mod 4 of
      1: If i = n then WriteLn(i) else Write(i, ' ');
      2: Write(i, ' ');
      end;
    end;
  end;
  2:
  begin
    WriteLn(1);
    Write(n div 2, ' ');
    For i := 1 to n do
    begin
      Case i mod 4 of
      2: If i = n then WriteLn(i) else Write(i, ' ');
      3: Write(i, ' ');
      end;
    end;
  end;
  3:
  begin
    WriteLn(0);
    Write(n div 2, ' ');
    For i := 1 to n do
    begin
      Case i mod 4 of
      3: If i = n then WriteLn(i) else Write(i, ' ');
      0: Write(i, ' ');
      end;
    end;
  end;
  end;
end.
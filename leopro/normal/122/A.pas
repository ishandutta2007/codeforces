program project1;

var
  N: LongInt;
  Happy: Boolean;

begin
  Readln(N);
  Happy := False;
  If N mod 4 = 0 then Happy := True;
  If N mod 7 = 0 then Happy := True;
  If N mod 44 = 0 then Happy := True;
  If N mod 47 = 0 then Happy := True;
  If N mod 74 = 0 then Happy := True;
  If N mod 77 = 0 then Happy := True;
  If N mod 444 = 0 then Happy := True;
  If N mod 447 = 0 then Happy := True;
  If N mod 474 = 0 then Happy := True;
  If N mod 477 = 0 then Happy := True;
  If N mod 744 = 0 then Happy := True;
  If N mod 747 = 0 then Happy := True;
  If N mod 774 = 0 then Happy := True;
  If N mod 777 = 0 then Happy := True;
  If Happy then WriteLn('YES') else WriteLn('NO');
end.
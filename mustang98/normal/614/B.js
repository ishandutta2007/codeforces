    (function f()    
    {
         var n = +readline();
         var k0=0;
         var kr=null;
         var m = readline().split(' ');
         //for (var i =0 ;i<m.length;i++) m[i] = +m[i];
         mm:for (var i = 0 ;i< m.length; i++)
         {
            if (m[i]=='0') {print(0); return 0;}
            if (m[i][0]!='1') {kr = m[i]; continue;}
            for (var j = 1;j<m[i].length;j++) if (m[i][j]!='0') {kr = m[i]; continue mm;}
            k0 += m[i].length-1;
         }
         if (kr === null) kr='1';
         var res = kr;
         //alert(k0);
         //alert(res);
         for (i = 0; i<k0;i++) res+='0';
         print(res);})()